echo "
    Введите 4 аргумента через запятую: 
    1) <имя>=<значение> (директория в которой будет осуществляться поиск нужных 
    файлов)
    2) <имя>=<значение> (искомый префикс)
    3) <имя>=<значение> (минимальный размер файла)
    4) <имя>=<значение> (максимальный размер файла)
    Скрипт найдёт все файлы, которые удовлетворяют заданным параметрам
    и удалит их, после чего выведет информацию об окончании работы скрипта.
    Если же таковых файлов нет в директории, то данная информация выведется на
    экран и, работа программы прекратится.
    
    Пример запуска программы:
    
    sh ./laba21.sh -folder=dir1, -prefix=pre_, -size_from=0, -size_to=40
    "
