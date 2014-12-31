var addon = require('./build/Release/hello');

var max = 100000;
//console.log('with c:');
//console.log(addon.hello(max));

function nextPrime(smallerThan) {
  for (;--smallerThan;) {
    var root = Math.sqrt(smallerThan);
    var divides = smallerThan != 2 && !(smallerThan % 2); // divides if not 2 and divisible by 2
    for (var i = 1; ++i <= root;) {
      ++i;
      if (!(smallerThan % i)) { // i divides smallerThan
        divides = true;
        break;
      }
    }
    if (!divides) {
      return smallerThan; // finds 1, o well
    }
  }
  return -1; // not found
}

function c() {
  console.log('c: ');
  console.log(addon.hello(max));
}
function js() {
  console.log('js: ');
  var str = '';
  for (var i = 1; ++i < max;) {
    str += nextPrime(i) +' ';
  }
  console.log(str);
}
//console.log(str);
exports.c = c;
exports.js = js;
