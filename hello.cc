#include <node.h>
#include <v8.h>
#include <math.h>

using namespace v8;

int nextPrime(int smallerThan) {
  for (;--smallerThan;) {
    int root = (int) sqrt((double)smallerThan);
    int divides = !(smallerThan % 2) && smallerThan != 2;   
    for (int i = 1; ++i <= root;) {
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

Handle<Value> Method(const Arguments& args) {
  HandleScope scope;
  //int prime = nextPrime(10);
  //int max = 200000;
  Local<Integer> val = Local<Integer>::Cast(args[0]);
  int max = (int)(val->Int32Value());
  //Local<Number> num = args[0]->NumberValue();
  //int max = (int) args[0];
  char strarr[max*4];
  char *str = strarr;
  int primes[max];  
  for (int i = max; --i >=0;) {
    primes[i] = 0;
  }
  int top = max;
  for (int i = max; --i > 1 && top > 2;) {
    primes[i] = nextPrime(top);
    //printf("%2d,", primes[i]);
    top = primes[i];
  }
  for (int i = -1; ++i < max;) {
    if (primes[i]) {
      sprintf(str, "%6d ", primes[i]);
      str += 7;
    }
  }
  return scope.Close(String::New(strarr));
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("hello"),
      FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(hello, init)
