# Паттерн синглтона

> NOTE: в многопоточном коде синглтоны работают плохо.

## Пример

```cpp
class Singleton
{
    static Singleton* instance; // in *.h
    // in *.cpp: Singleton* Singeton::instance = nullptr;

    // for calling Singleton::instance, but u cant do this because of private
    Signleton();
    Singleton(const Singleton&);

public:
    Signleton();

    // static method dont have this
    static Singleton* getInstance()
    {
	if (instance == nullptr)
	   instance = new Singleton();
	return instance;
    }
}

int main()
{
    Singleton* s = Singleton::getInstance();
    // recieving access to the 1 object
}
```