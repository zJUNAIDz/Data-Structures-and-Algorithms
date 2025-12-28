function checkValidString(s: string): boolean {
  let minOpen: number = 0;
  let maxOpen: number = 0;

  for (const c of s) {
    if (c === '(') {
      minOpen++;
      maxOpen++;
    } else if (c === ')') {
      minOpen--;
      maxOpen--;
    } else if (c === '*') {
      minOpen--;
      maxOpen++;
    }
    if (maxOpen < 0) return false;
    if (minOpen < 0) minOpen = 0;
  }
  return minOpen === 0
};
