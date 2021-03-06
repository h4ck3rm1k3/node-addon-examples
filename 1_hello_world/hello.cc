#include <node.h>

using namespace v8;

template<class T> void Method(const v8::FunctionCallbackInfo<T>& info) {
  HandleScope scope(Isolate::GetCurrent());
  info.GetReturnValue().Set(String::New("world"));
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("hello"),
      FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(hello, init)
