#include "group.h"
#include <iostream>
#include <string>
using namespace std;

// not interaction between function:  

//              Group 
// ********************************
Group::Group(const std::string & name ): Groupname{name}, emailnode{nullptr}, groupnode{nullptr} {}

Group::~Group(){    // delete group??? how to do it?? 
   delete emailnode;
   delete groupnode;
}

std::string Group::name() const{  // return the group's name
   return Groupname;
}   

// return a string containing all of the email addresses in the group
std::string Group::emails() const{ 
   string output = "";                         
   if (emailnode) {                                    // if emailnode exist
     output += emailnode->emailnodename;
     EmailNode * k = emailnode->next;
     while (k) {
      output += ", ";
      output += k->emailnodename;
      k = k->next;
     }
     return output;
   } 
   return output;                                       // if emailnode not exist
}

//             EmailNode
// ******************************************   
// EmailNode 
Group::EmailNode::EmailNode( const std::string & emailname): emailnodename{emailname}, next{nullptr} {}

// finish
Group::EmailNode::~EmailNode() {
     delete next;
}

std::string Group::EmailNode::address() const{
     return emailnodename;
}

//             GroupNode
// ****************************************************
// GroupNode
Group::GroupNode::GroupNode(Group * subgroup): subgroup{subgroup}, next{nullptr} {}

// 
Group::GroupNode::~GroupNode() {
   delete subgroup;
   //subgroup->~Group();
   delete next;
}

// 
Group * Group::GroupNode::group() const{
    return subgroup;
}






// From here is for the function which will have interaction between different class


//                No.1 
//               addAddress
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//             Group:

void Group::addAddress(const std::string & addressname){ // add the given email address to the group   
     if (emailnode == nullptr){                                                 // emailnode not exist
       emailnode = new EmailNode(addressname); 
       return;
     } 
     
     emailnode->addAddress(addressname);                                         // emailnode exist
       
              
     
}

//              EmailNode:

void Group::EmailNode::addAddress( const std::string & addressname){
     if (next == nullptr){                                                       // next not exist
        next = new EmailNode(addressname);
        return;
     }   
     next->addAddress(addressname);                                              // next exist
}



//               No.2
//               addGroup
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//             Group:

void Group::addGroup( Group * groupname){                   // add the group as a subgroup to this one
    GroupNode * new_groupnode = new GroupNode(groupname);   // create new_groupnode
    if (groupnode == nullptr) {                                 // when groupnode in group is nullptr
       groupnode = new_groupnode;
       return;
    }  
    if (groupnode->subgroup->Groupname > groupname->Groupname) { //  groupname < subgroup's Groupname
        new_groupnode->next = groupnode;
        groupnode = new_groupnode;
    } else {                                                     // search rest groupnode
        groupnode->addGroup(new_groupnode);
    }
     
    
}

//              GroupNode:
void Group::GroupNode::addGroup( GroupNode* groupnodename){ // add to the subgroup, in lexicographic order
    if (next == nullptr) {                                      
       next = groupnodename;
       return;
    }
    if (next->subgroup->Groupname > groupnodename->subgroup->Groupname){
         groupnodename->next = next;
         next = groupnodename;
    } else {
         next->addGroup(groupnodename);
    }
    
}


//                 No.3
//                findGroup
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//             Group:

Group::GroupNode * Group::findGroup( const std::string & groupname ){
     if (!groupnode) {                                          //  None groupnode , return nullptr
        return nullptr;
     }
     GroupNode * returngroup = nullptr;                         // create a nullptr GroupNode 
     returngroup = groupnode->findGroup(groupname);   
     if (returngroup) {                                         // search its groupnode subgroup
        return returngroup;
     } 
     
     return returngroup;
}

//              GroupNode:

Group::GroupNode * Group::GroupNode::findGroup (const std::string & groupname) {
     GroupNode * returngroup = nullptr;                // create a nullptr GroupNode 
     if (subgroup->Groupname == groupname) {
        GroupNode * temp = this;
        return temp;
     }

     returngroup = subgroup->findGroup(groupname);     // searching the subgroup 
     if (returngroup) {
        return returngroup;
     }
     if (next) {                                       // if next exist, go through next
        returngroup = next->findGroup(groupname);
     }
     if (returngroup) {
        return returngroup;
     }
     return returngroup;

} 


//                 No.4
//                findAddress
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                Group:
Group::EmailNode * Group::findAddress( const std::string & addressname) {
     EmailNode * returnname = nullptr;
     if (emailnode) {
        if (emailnode->emailnodename == addressname) {        // find EmailNode first
           returnname = emailnode;
           return returnname;
        }
        returnname = emailnode->findAddress(addressname);
     }

     if (returnname){  
                                                            // if addressname in EmailNode
        return returnname;       
     } else {                                                 // find in GroupNode    returnname == nullptr
       if (groupnode) {
          GroupNode * targetgroup = nullptr;
          targetgroup = groupnode->findAddress(addressname);  // find addressname in which GroupNode's group
          if (targetgroup) {                                  // if find address in a targetgroup
             returnname = targetgroup->subgroup->findAddress(addressname);
             return returnname;
          } 
       }
       return returnname;                                     // there is no emailnode and groupnode
     }
     return returnname;
}



//               EmailNode:

Group::EmailNode * Group::EmailNode::findAddress( const std::string & addressname){
     if (next) {                                               // if next exist
        if (next->emailnodename == addressname) {
           return next;
        }
        return next->findAddress(addressname);
     }
     return nullptr;                                            // if next not exist
}



//                GroupNode:
Group::GroupNode * Group::GroupNode::findAddress( const std::string & addressname){
      Group::EmailNode * returnname = nullptr;
      Group::EmailNode * emailreturnname = nullptr;
      emailreturnname = subgroup->emailnode->findAddress(addressname);
      returnname = subgroup->findAddress(addressname);
      
      if ((emailreturnname)||(subgroup->emailnode->emailnodename == addressname)) {  // if emailreturnname exist in the first emailnode
         return this;                                                               
      }
      if ((!((emailreturnname)||(subgroup->emailnode->emailnodename == addressname)))&&(returnname)) {
         return subgroup->groupnode->findAddress(addressname);
      }
      if (next) {
         return next->findAddress(addressname);
      }
      return nullptr;
}




//                 No.5
//                removeGroup
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                 Group:

bool Group::removeGroup( const std::string & removename){ // remove the first occurrence of the subgroup with that name
     if (groupnode) {
        if (groupnode->subgroup->Groupname == removename) {
           GroupNode *temp = groupnode;
           groupnode = groupnode->next;
           temp->next = nullptr;
           delete temp;
           return true;
        }

        if ((groupnode->subgroup->removeGroup(removename))||(groupnode->removeGroup(removename))){
           return true;
        } 
                                         // look the removename from down and right
     }
     return false;
}



//                GroupNode:


bool Group::GroupNode::removeGroup( GroupNode* removenodename){ // remove from the linked list
     if (next) {
        if (next->subgroup->Groupname == removenodename->subgroup->Groupname) {
           GroupNode * temp = removenodename;
           next = next->next;
           temp->next = nullptr;
           delete temp;
           return true;
        } else {
          return next->removeGroup(removenodename);
        }
     } 
     return false;
}



// Remove the first occurrence of the group whose name is the specified string
bool Group::GroupNode::removeGroup( const std::string & removename){
    if (next) {
       if (next->subgroup->Groupname == removename) {                  // if the next name of subgroup is equal to removename
          GroupNode * temp = next;
          next = next->next;
          temp->next = nullptr;
          delete temp;
          return true;
       } 
       if ((next->subgroup->removeGroup(removename))||(next->removeGroup(removename))){ // else go to subgroup groupnode first 
           return true; 
       }
    }                                                                                      // and then next
    return false;
}




//                 No.6
//                removeAddress
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                 Group:

bool Group::removeAddress( const std::string & removename){ // remove the first occurrence of the address
    // seperate into four different situation, 1. only emailnode exist 2. only groupnode exist 3. both email&group node exist 4. none exist
    if ((!emailnode)&&(!groupnode)) {                              //  none exist
       return false;
    } 

   if ((emailnode)&&(!groupnode)) {                                //  if only emailnode exist
       if (emailnode->emailnodename == removename) {
           EmailNode * temp = emailnode;
           emailnode = emailnode->next;
           temp->next = nullptr;
           delete temp;
           return true;
       }
       return emailnode->removeAddress(removename);
    }  else if ((!emailnode)&&(groupnode)){                        //  if only groupnode exist
       return ((groupnode->subgroup->removeAddress(removename))||(groupnode->removeAddress(removename)));
    }  else {                                                      //  if both exist
       if (emailnode->emailnodename == removename) {
           EmailNode * temp = emailnode;
           emailnode = emailnode->next;
           temp->next = nullptr;
           delete temp;
           return true;
       }
       if (emailnode->removeAddress(removename)) {
          return true;
       }
       return ((groupnode->subgroup->removeAddress(removename))||(groupnode->removeAddress(removename))); 
    }
    return false;
}






//                EmailNode:
bool Group::EmailNode::removeAddress( const std::string & removename){
     if (next) {                                                   // if next exist
        if (next->emailnodename == removename) {                   
           EmailNode * temp = next;
           next = next->next;
           temp->next = nullptr;
           delete temp;
           return true;
        }
        return next->removeAddress(removename);
     }
     return false;                                                  // dont exist removename in the EmailNode
}


//                GroupNode:
// Remove the first occurrence of the specified email address from the group
bool Group::GroupNode::removeAddress( const std::string & removename){          
     if (next) {                                                     // if next exist in subgroup
        return ((next->subgroup->removeAddress(removename))||(next->removeAddress(removename)));
     }
     return false;                                                   // no next
} 


//                   No.7
//                  operator
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                 Group:

void print(Group::GroupNode & groupnode, int k) {
   for (int i = 0; i < k; ++i) {
     cout << '\t';
   }
   cout << groupnode.subgroup->name() << endl;
   for (int i = 0; i < k; ++i) {
     cout << '\t';
   }
   cout << "["<< groupnode.subgroup->emails() << "]" << endl;
   k += 1;
   Group::GroupNode * temp = groupnode.subgroup->groupnode;
   while (temp) {
      print(*(temp), k);
      temp = temp->next;
   }
}

std::ostream & operator<<( std::ostream & out, Group & groupname){
    int k = 0;
    out << groupname.name() << endl;
    out << "[" << groupname.emails() << "]"<< endl;          // print the emailaddress in group
    k += 1;   
    Group::GroupNode * temp = groupname.groupnode;
    while(temp) {
       print(*(temp), k);
       temp = temp->next;
    }
    return out;

}




std::ostream & operator<<(std::ostream & out, Group::EmailNode & emailnodename){
    out << emailnodename.address();                         // use addresss() print all emailaddres in EmailNode
    return out;
}



std::ostream & operator<<(std::ostream & out, Group::GroupNode & groupnodename){
    out << *(groupnodename.subgroup);                       // if exist subgroup 
    return out;
}












