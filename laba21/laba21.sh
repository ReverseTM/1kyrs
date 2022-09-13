status=0

#если в аргументы передаётся "-?", то запускаается конфиг, где записана спецификация
if [ "$1" = -? ] || [ "$2" = -? ] || [ "$3" = -? ] || [ "$4" = -? ]; then
    . .config.sh
    exit $status
else
    if [ $1 ]; then
        dir=$1
        dir=`echo "${dir#*=}" | rev | cut -c 2- | rev` #"${dir#*=}" выводит переменную dir от знака =, т.е. dir: abac=34 , выведет 34, rev - reverse, cut -c 2- обрезает первый символ.
    fi

    if [ $2 ]; then
        prefix=$2
        prefix=`echo "${prefix#*=}" | rev | cut -c 2- | rev` 
    fi

    if [ $3 ]; then
        size_from=$3
        size_from=`echo "${size_from#*=}" | rev | cut -c 2- | rev`
    fi

    if [ $4 ]; then
        size_to=$4
        size_to=`echo "${size_to#*=}"`
    fi

    echo -n "Хотите ли изменить званечение параметров? (y/n) "

    read answer #как сканф
    case "$answer" in # указываются условия, которые могут встретится в переменной и при этом выполнится какой-то алгоритм
        y|Y|д|Д) echo "Текущая директория: "$dir #y|Y|д|Д) -это то что может встертится (|) - или, обязятельно нужно закрыть скобкой. Каждое условие нужно закрывать (;;)
            echo -n "Введите новую директорию: "
            read new_parametrs
            case "$new_parametrs" in
                *)  if [ -z "$new_parametrs" ]; then #(*)- любая последовательность, -z даёт true, если параметр пустой
                        echo "Директория: "$dir
                    else
                        dir=$new_parametrs
                        echo "Новое значение директории: "$dir    
                    fi
                ;;
            esac
            echo "Текущий префикс: "$prefix
            echo -n "Введите новый префикс: "
            read new_parametrs
            case "$new_parametrs" in
                *)  if [ -z "$new_parametrs" ]; then
                        echo "Префикс: "$prefix
                    else
                        prefix=$new_parametrs
                        echo "Новое значение префикса: "$prefix    
                    fi
                ;;
            esac
            echo "Текущий минимальный размер файла: "$size_from
            echo -n "Введите новый минимальный размер файла: "
            read new_parametrs
            case "$new_parametrs" in
                *)  if [ -z "$new_parametrs" ]; then
                        echo "Минимальный размер файла: "$size_from
                    else
                        size_from=$new_parametrs
                        echo "Новое значение минимального размера файла: "$size_from  
                    fi
                ;;
            esac
            echo "Текущий максимальный размер файла: "$size_to
            echo -n "Введите новый максимальный размер файла: "
            read new_parametrs
            case "$new_parametrs" in
                *)  if [ -z "$new_parametrs" ]; then
                        echo "Максимальный размер: "$dir
                    else
                        size_to=$new_parametrs
                        echo "Новое значение максимального размера: "$size_to    
                    fi
                ;;
            esac
            ;;
        n|N|н|Н) echo "Параметры оставилсь неизменными"
            ;;
        *) echo "Параметры оставилсь неизменными"
            ;;
    esac
    path=`pwd`
    if ! [ -d $path/$dir ]; then
        echo 'Введённой директории не существует'
        status=0
        exit $status
    else
        finds=`find $dir -type f -name "$prefix*" -size +$size_from -size -$size_to | awk -F: '{ print $1 }'`
        #записываю в переменную все файлы которые нашлись

        if [-z $finds] ; then #${#finds[@]} - сколько элементов, -eq 0 эквивалетно нулю
            echo "Файлы по данным параметрам не найдены"
        else
            echo "Найденные файлы: "
            for i in $finds; do
                echo $i
            done

            echo "Удаляю..."
            for i in $finds; do
                rm $i
                if [ $? -ne 0 ]; then #$? - последняя команда ( в моём случае rm $i) -ne 0 (не ноль)
                    echo "При удалении что-то пошло не так"
                    status=2
                fi
            done
            echo "Файлы удалены!"
        fi
    fi
fi
exit $status #как return 0
