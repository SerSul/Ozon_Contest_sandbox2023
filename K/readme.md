# K. Пользователи и заказы (SQL, 10 баллов)
- ограничение по времени на тест: *15 секунд*
- ограничение по памяти на тест: *1024 мегабайта*
- ввод: *стандартный ввод*
- вывод" *стандартный вывод*
- ***
Это необычная задача — вам надо написать SQL-запрос.
В качестве решения вы должны отослать один запрос к базе данных, который возвращает требуемые данные.
При проверке вашего решения используется PostgreSQL 15.1.
В качестве входных данных вам предоставляется дамп состояния базы данных. Обратите внимание,
что время работы вашего решения на тесте включает восстановление состояния базы данных из дампа,
но это время значительно меньше ограничения по времени.
Вы можете использовать сервис http://sqlfiddle.com/ как инструмент для запуска запросов.

Напишите запрос к базе данных, который возвращает всех пользователей, сделавших хотя бы один заказ.
Выведите всех таких пользователей, отсортировав их по имени (при равенстве по id).

Схема базы данных содержит две таблицы: users и orders, которые связаны отношением «один ко многим».
Изучите входные данные примера, чтобы подробно ознакомиться со схемой базы данных.
Диаграмма ниже иллюстрирует схему базы данных.

### Входные данные

Входными данными в этой задаче является дамп базы данных.
Вам он может быть полезен для ознакомления с состоянием базы данных для конкретного теста.
В качестве решения вы должны отправить один SQL-запрос.

### Выходные данные

Ваш SQL-запрос должен вывести всех пользователей в порядке неубывания их имён (по возрастанию id при равенстве имён).
Используйте collation по умолчанию.