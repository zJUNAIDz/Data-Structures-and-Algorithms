const deb = debounce(console.log, 1000);
function debounce(func, ms) {
  let timeout;
  return function () {
    clearTimeout(timeout);
    timeout = setTimeout(() => func.apply(this, arguments), ms);
  };
}
deb("zamn");
deb("zamn");
deb("zamn");
