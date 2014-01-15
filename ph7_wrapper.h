#ifndef HAVE_PH7W_H
#define HAVE_PH7W_H

#include <node.h>
extern "C" {
	#include "ph7.h"
}

class ph7_wrapper : public node::ObjectWrap {
	public:
		// *structorz...
		ph7_wrapper();
		~ph7_wrapper();
		// NodeJS specific
		static void init(v8::Handle<v8::Object> exports);
		static v8::Handle<v8::Value> New(const v8::Arguments& args);	
		
		// Actual ph7 method
		static v8::Handle<v8::Value> create(const v8::Arguments& args);

		// VM methods	
		static v8::Handle<v8::Value> vm_addSuper(const v8::Arguments& args);
		static v8::Handle<v8::Value> vm_addVar(const v8::Arguments& args);
		static v8::Handle<v8::Value> vm_config(const v8::Arguments& args);
		static v8::Handle<v8::Value> vm_compile(const v8::Arguments& args);
		static v8::Handle<v8::Value> vm_compileFile(const v8::Arguments& args);
		// Convinience method
		static v8::Handle<v8::Value> vm_run(const v8::Arguments& args);
		// Getter and setter
		static v8::Handle<v8::Value> vm_getter(v8::Local<v8::String> property, const v8::AccessorInfo& info);
		static void vm_setter(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);

		// Helper: printing stuff...straightforward.
		static void print(const void *msg, unsigned int len, void *userData);
		
	private:
		// These things may only be seen from within the methods above.
		// Configuration...
		ph7* engine;
		ph7_vm* pVM;
		bool outputBuffering;
		bool errorBuffering;
		bool useTags;
		bool reportAll;
		v8::Persistent<v8::Array> includePath;
		// Script config
		v8::Persistent<v8::Array> $_SERVER;
		v8::Persistent<v8::Array> $_ENV;
		v8::Persistent<v8::Array> $_HEADERS;
		v8::Persistent<v8::Array> $_GET;
		v8::Persistent<v8::Array> $_POST;
		v8::Persistent<v8::Array> $_COOKIE;
		v8::Persistent<v8::Array> $_SESSION;
		v8::Persistent<v8::Array> $argv;
		v8::Persistent<v8::Array> $_GLOBALS;
		v8::Persistent<v8::Array> $_SUPER_GLOBALS;
};

#endif