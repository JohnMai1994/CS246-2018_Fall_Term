void helper(int *mem) {
  delete [] mem;
}
int main() {
  int elements[3];
  helper(elements);
  return 0;
}
