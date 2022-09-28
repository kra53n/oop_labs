# наследование

## `Unit`

```cpp
class Unit
{
protected:
    int hp, atk, mp;

public:
    Unit(int hp, int atk, int mp);
    Atk();
    Move();
    RcvDmg();
}
```

## `Archer`

`Archer` - наследник `Unit`.

```cpp
class Archer
{
protected:
    int range, ammo;

public:
    RngAtk();
    Archer(int hp, int atk, int range, int ammo);
}
```


## Примеры

- [пример 1](examples/inheritance/ex1)