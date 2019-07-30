hModule := DllCall("LoadLibrary", "Str", "./build/Debug/module.dll", "Ptr") 
result:=DllCall("module\module_init","UInt", 18, "Cdecl AStr")
msgbox, % result
DllCall("FreeLibrary", "Ptr", hModule)