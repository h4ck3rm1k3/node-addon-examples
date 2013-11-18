#include <node.h>
#include <v8.h>

using namespace v8;

//const Arguments& args
void Method(const v8::FunctionCallbackInfo<Value>& info) {
  HandleScope scope(Isolate::GetCurrent()); 
  v8::Local<v8::String> world = scope.Close(String::New("world"));
  info.GetReturnValue().Set(world);

}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("hello"),
      FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(hello, init)
