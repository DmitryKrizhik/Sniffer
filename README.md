# *__Оглавление__*
*__Сборка проекта__*
  * Требования к сборке
  
*__Запуск проекта__*
  * Требования к запуску проекта
  * Пример запуска через консоль
  * Пример запуска Unit-тестов
  
  
___
## *__Сборка проекта__*

*__Требования к сборке проекта__*

Сборка проекта осуществяется с использованием  [CMake](https://cmake.org/download/) версии от __3.2__ и компилятора, поддерживающего __C++11__.

*__Пример сборки через консоль__*

- Скачиваем репозиторий и создаём директорию для сборки _build_
```
$ git clone https://github.com/DmitryKrizhik/Sniffer
$ cd Sniffer 
$ mkdir build 
$ cd build
```
- Генерируем проектные файлы и производим сборку проекта
```
$ cmake ..
$ make
```
## *__Запуск проекта__*
Проект можно запустить в нескольких режимах работы:
* Short mode
* Standard mode
* Long mode

От выбора режима зависит время выполнения программы:
* Short mode - 15 секунд
* Standard mode - 30 секунд
* Long mode - 60 секунд

Также, можно выбрать порт, с которого программа будет производить прослушивание. Примеры портов:
* 127.0.0.1 - для полноценных(lo)
* 10.0.2.15 - для виртуальных версий ОС(ОСenp0s3) (VirtualBox)

__Примеры запуска программы через консоль в виртуальной версии OC Ubuntu:__
* __Запуск короткого режима режиме(Short mode):__
```
$sudo ./app 1 10.0.2.15
```
* __Запуск стандартного режима режиме(Standard mode):__
```
$sudo ./app 2 10.0.2.15
```
* __Запуск долгого режима режиме(Long mode):__
```
$sudo ./app 3 10.0.2.15
```
После запуска программы во втором окне консоли трижды запускаем команду:
```
$curl 'http://vk.ru'
```
По истечению времени работы программы получаем такой вывод:
```
[2023-04-19 18:07:05.110] [info] Sniffer<Short mode>

[2023-04-19 18:07:05.110] [info] Sniffer<interfaceIPAddr = 10.0.2.15>
[2023-04-19 18:07:05.168] [info] IPv4Check<Method started>
[2023-04-19 18:07:05.168] [info] IPv4Check<Interface found>
[2023-04-19 18:07:05.168] [info] PrintAboutInterface<Method started>

Interface info:
   Interface name:        enp0s3
   MAC address:           08:00:27:1c:1b:98
   Default gateway:       10.0.2.2
   Interface MTU:         1500
   Interface IP:          10.0.2.15
   DNS server:            192.168.31.1

[2023-04-19 18:07:05.168] [info] DevOpeningCheck<Method started>
[2023-04-19 18:07:05.204] [info] DevOpeningCheck<Device opened successful>
[2023-04-19 18:07:05.204] [info] clear<Method started>
[2023-04-19 18:07:05.204] [info] Starting capture with packet vector...

[2023-04-19 18:07:21.205] [info] CollectStatistics<Method started>
URL:vk.ru   Layer type: HTTPRequest; Total data: 68 [bytes]; Layer data: 68 [bytes]; Layer payload: 0 [bytes]
URL:vk.ru   Layer type: HTTPResponse; Total data: 416 [bytes]; Layer data: 252 [bytes]; Layer payload: 164 [bytes]
URL:vk.ru   Layer type: HTTPRequest; Total data: 68 [bytes]; Layer data: 68 [bytes]; Layer payload: 0 [bytes]
URL:vk.ru   Layer type: HTTPResponse; Total data: 416 [bytes]; Layer data: 252 [bytes]; Layer payload: 164 [bytes]
URL:vk.ru   Layer type: HTTPRequest; Total data: 68 [bytes]; Layer data: 68 [bytes]; Layer payload: 0 [bytes]
URL:vk.ru   Layer type: HTTPResponse; Total data: 416 [bytes]; Layer data: 252 [bytes]; Layer payload: 164 [bytes]

[2023-04-19 18:07:21.205] [info] PrintURLcount<Method started>

vk.ru: 6
HTTPRequests: 3 HTTPResponse: 3

[2023-04-19 18:07:21.205] [info] printToConsole<Method started>
Results:
Ethernet packet count: 45
IPv4 packet count:     45
IPv6 packet count:     0
TCP packet count:      35
UDP packet count:      10
DNS packet count:      6
HTTP packet count:     6
SSL packet count:      0
[2023-04-19 18:07:21.205] [info] Sniffer<dev->close()>
```
Попробуем запустить выполнение программы в виртуальной версии ОС таким образом:
```
$sudo ./app 1 127.0.0.1
```
После запуска начала работы программы снова трижды запускаем команду:
```
$curl 'http://vk.ru'
```
Получим такой вывод:
```
[2023-04-19 18:16:05.358] [info] Sniffer<Short mode>

[2023-04-19 18:16:05.358] [info] Sniffer<interfaceIPAddr = 127.0.0.1>
[2023-04-19 18:16:05.419] [info] IPv4Check<Method started>
[2023-04-19 18:16:05.419] [info] IPv4Check<Interface found>
[2023-04-19 18:16:05.419] [info] PrintAboutInterface<Method started>

Interface info:
   Interface name:        lo
   Interface description: 
   MAC address:           00:00:00:00:00:00
   Default gateway:       0.0.0.0
   Interface MTU:         65536
   Interface IP:          127.0.0.1
   DNS server:            192.168.31.1

[2023-04-19 18:16:05.419] [info] DevOpeningCheck<Method started>
[2023-04-19 18:16:05.484] [info] DevOpeningCheck<Device opened successful>
[2023-04-19 18:16:05.484] [info] clear<Method started>
[2023-04-19 18:16:05.484] [info] Starting capture with packet vector...

[2023-04-19 18:16:21.484] [info] CollectStatistics<Method started>

[2023-04-19 18:16:21.485] [info] PrintURLcount<Method started>

HTTPRequests: 0 HTTPResponse: 0

[2023-04-19 18:16:21.485] [info] printToConsole<Method started>
Results:
Ethernet packet count: 12
IPv4 packet count:     12
IPv6 packet count:     0
TCP packet count:      0
UDP packet count:      12
DNS packet count:      12
HTTP packet count:     0
SSL packet count:      0
[2023-04-19 18:16:21.485] [info] Sniffer<dev->close()>
```
*Из данного вывода можно понять, что в виртуальной версии ОС при запуске программы с порта 127.0.0.1 программа отрабатывает некорректно*

__Собрать статистику можно и другим способом:__
* Заходим на сайт(или на несколько сайтов), работающий на протоколе __http__
* Отправляем запросы путём прокликивания всевозможных кнопок

В итоге получаем такой вывод:
```
[2023-04-19 21:45:58.334] [info] IPv4Check<Method started>
[2023-04-19 21:45:58.334] [info] IPv4Check<Interface found>
[2023-04-19 21:45:58.334] [info] PrintAboutInterface<Method started>

Interface info:
   Interface name:        enp0s3
   MAC address:           08:00:27:1c:1b:98
   Default gateway:       10.0.2.2
   Interface MTU:         1500
   Interface IP:          10.0.2.15
   DNS server:            192.168.31.1

[2023-04-19 21:45:58.334] [info] DevOpeningCheck<Method started>
[2023-04-19 21:45:58.377] [info] DevOpeningCheck<Device opened successful>
[2023-04-19 21:45:58.377] [info] clear<Method started>
[2023-04-19 21:45:58.377] [info] Starting capture with packet vector...

[2023-04-19 21:46:29.380] [info] CollectStatistics<Method started>
URL: biography.artyx.ru  Layer type: HTTPRequest; Total data: 894 [bytes]; Layer data: 894 [bytes]; Layer payload: 0 [bytes]
URL: biography.artyx.ru  Layer type: HTTPResponse; Total data: 2920 [bytes]; Layer data: 265 [bytes]; Layer payload: 2655 [bytes]
URL: dd.cc.b0.a1.top.list.ru  Layer type: HTTPRequest; Total data: 412 [bytes]; Layer data: 412 [bytes]; Layer payload: 0 [bytes]
URL: dd.cc.b0.a1.top.list.ru  Layer type: HTTPResponse; Total data: 921 [bytes]; Layer data: 921 [bytes]; Layer payload: 0 [bytes]
URL: artyx.ru  Layer type: HTTPRequest; Total data: 620 [bytes]; Layer data: 620 [bytes]; Layer payload: 0 [bytes]
URL: dd.cc.b0.a1.top.list.ru  Layer type: HTTPRequest; Total data: 527 [bytes]; Layer data: 527 [bytes]; Layer payload: 0 [bytes]
URL: artyx.ru  Layer type: HTTPRequest; Total data: 620 [bytes]; Layer data: 620 [bytes]; Layer payload: 0 [bytes]
URL: iznedr.ru  Layer type: HTTPRequest; Total data: 412 [bytes]; Layer data: 412 [bytes]; Layer payload: 0 [bytes]
URL: iznedr.ru  Layer type: HTTPResponse; Total data: 920 [bytes]; Layer data: 331 [bytes]; Layer payload: 589 [bytes]
URL: iznedr.ru  Layer type: HTTPResponse; Total data: 1456 [bytes]; Layer data: 332 [bytes]; Layer payload: 1124 [bytes]
URL: iznedr.ru  Layer type: HTTPResponse; Total data: 1036 [bytes]; Layer data: 1036 [bytes]; Layer payload: 0 [bytes]
URL: iznedr.ru  Layer type: HTTPResponse; Total data: 2087 [bytes]; Layer data: 332 [bytes]; Layer payload: 1755 [bytes]
URL: iznedr.ru  Layer type: HTTPRequest; Total data: 412 [bytes]; Layer data: 412 [bytes]; Layer payload: 0 [bytes]
URL: iznedr.ru  Layer type: HTTPRequest; Total data: 412 [bytes]; Layer data: 412 [bytes]; Layer payload: 0 [bytes]
URL: iznedr.ru  Layer type: HTTPResponse; Total data: 2035 [bytes]; Layer data: 332 [bytes]; Layer payload: 1703 [bytes]
URL: iznedr.ru  Layer type: HTTPResponse; Total data: 1995 [bytes]; Layer data: 332 [bytes]; Layer payload: 1663 [bytes]
URL: www.acint.net  Layer type: HTTPRequest; Total data: 485 [bytes]; Layer data: 485 [bytes]; Layer payload: 0 [bytes]
URL: www.acint.net  Layer type: HTTPRequest; Total data: 336 [bytes]; Layer data: 336 [bytes]; Layer payload: 0 [bytes]
URL: www.acint.net  Layer type: HTTPRequest; Total data: 1147 [bytes]; Layer data: 1147 [bytes]; Layer payload: 0 [bytes]
URL: www.acint.net  Layer type: HTTPResponse; Total data: 345 [bytes]; Layer data: 203 [bytes]; Layer payload: 142 [bytes]
URL: www.acint.net  Layer type: HTTPResponse; Total data: 358 [bytes]; Layer data: 216 [bytes]; Layer payload: 142 [bytes]
URL: www.acint.net  Layer type: HTTPResponse; Total data: 1108 [bytes]; Layer data: 966 [bytes]; Layer payload: 142 [bytes]
URL: cse.google.com  Layer type: HTTPRequest; Total data: 380 [bytes]; Layer data: 380 [bytes]; Layer payload: 0 [bytes]
URL: cse.google.com  Layer type: HTTPResponse; Total data: 331 [bytes]; Layer data: 331 [bytes]; Layer payload: 0 [bytes]
URL: clients1.google.com  Layer type: HTTPRequest; Total data: 393 [bytes]; Layer data: 393 [bytes]; Layer payload: 0 [bytes]
URL: clients1.google.com  Layer type: HTTPResponse; Total data: 127 [bytes]; Layer data: 127 [bytes]; Layer payload: 0 [bytes]
URL: www.acint.net  Layer type: HTTPRequest; Total data: 497 [bytes]; Layer data: 497 [bytes]; Layer payload: 0 [bytes]
URL: www.acint.net  Layer type: HTTPResponse; Total data: 458 [bytes]; Layer data: 316 [bytes]; Layer payload: 142 [bytes]
URL: www.acint.net  Layer type: HTTPRequest; Total data: 492 [bytes]; Layer data: 492 [bytes]; Layer payload: 0 [bytes]
URL: www.acint.net  Layer type: HTTPResponse; Total data: 453 [bytes]; Layer data: 311 [bytes]; Layer payload: 142 [bytes]

[2023-04-19 21:46:29.382] [info] PrintURLcount<Method started>

artyx.ru : 4
biography.artyx.ru : 2
clients1.google.com : 2
cse.google.com : 2
dd.cc.b0.a1.top.list.ru : 4
iznedr.ru : 6
www.acint.net : 10
HTTPRequests: 15 HTTPResponse: 15

[2023-04-19 21:46:29.382] [info] printToConsole<Method started>
Results:
Ethernet packet count: 1735
IPv4 packet count:     1735
IPv6 packet count:     0
TCP packet count:      1001
UDP packet count:      734
DNS packet count:      186
HTTP packet count:     30
SSL packet count:      299
[2023-04-19 21:46:29.382] [info] Sniffer<dev->close()>
```
## *__Пример запуска Unit-тестов__*
Для запуска Unit-тестов из директории сборки:
```
$sudo ./SnifferLibrary/Tests/TestApp
```

Получаем вывод:
```
[==========] Running 2 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 1 test from AppSuiteException
[ RUN      ] AppSuiteException.ThrowException
[2023-04-19 21:53:51.445] [info] IPv4Check<Method started>
Cannot find interface with IPv4 address of ''
EXPECT_THROW 1 - DONE
EXPECT_THROW 2 - DONE
EXPECT_THROW 3 - DONE
EXPECT_THROW 4 - DONE
EXPECT_THROW 5 - DONE
[       OK ] AppSuiteException.ThrowException (0 ms)
[----------] 1 test from AppSuiteException (0 ms total)

[----------] 1 test from AppAssertion
[ RUN      ] AppAssertion.AssertionCheck
EXPECT_EQ 1 - DONE
EXPECT_GT 1 - DONE
[       OK ] AppAssertion.AssertionCheck (0 ms)
[----------] 1 test from AppAssertion (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test suites ran. (0 ms total)
[  PASSED  ] 2 tests.
```




