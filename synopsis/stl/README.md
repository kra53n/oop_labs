# STL

STL - Standard Template Library.

STL содержит коллекции или контейнеры (классы с данными).

Для использования коллекции нужно включить библиотеку с
соответствующим названием.

## Коллекции

### Последовательные коллекции

- `array<T, N>`, `[]`
- `vector<T>`, `[]`
- `list<T>`
- `deque<T>`, `[]` - список, реализованный на кусочных массивах
- `forward_list<T>` - очередь

### Адаптеры

Используют возможности других контейнеров, но ограничивают их в
чём-то.

- `queue<T>`
- `stak<T>`
- `priority_queue<T, Cont, Compare>` - поддерживает элементы в
  упорядоченной последовательности

### Ассоциативные контейнеры

Все ассоциативные контейнеры устроены деревом.

- `set<T>`
- `unordered_set<T>`
- `map<K, V>` - карта, словарь, ассоциативный массив
- `unordered_map<K, V>`
- `multimap<K, V>` - к одному и тому же ключу могут существовать
  разные значения
- `multiset<K>` - хранит значение встречаемости ключей

### string, xstring

- `string`
- `wstring` - строка, которая хранит символы из Unicode
  таблицы. wstring s = L"Hello". L - означает, что после идёт
  текстовая Unicode константа. `<xstring>`

### utility

- `pair<T, V>`

### iterator

`cont<...>::iterator`

Прегруженные операторы:
- `*`
- `++`

- [Пример работы с итераторами](iteration.cpp)

## Методы коллекций

### Методы размеров

#### Методы списков

- `empty`
- `size`
- `max_size` - потенциальое выделение для памяти для элементов списка

#### Методы вектора

- `capacity`
- `resize`
- `reserve` - управляет `capacity`, нельзя уменьшить `capacity` этим методом
- `shrink_to_fit` - сжать в притык, `capacity == size ~> true`

### Методы итераторов

- `begin` - указатель на первый элемент. Если у коллекции нет элементов `begin` возвращает `end`
- `end` - указатель на следующий элемент после последнего элемента (терминальный символ), нельзя разыминовать
- `rbegin`
- `rend`
- `cbegin` - указатель на первый элемент. Если у коллекции нет элементов `begin` возвращает `end`
- `cend` - указатель на следующий элемент после последнего элемента (терминальный символ), нельзя разыминовать
- `crbegin`
- `crend`
