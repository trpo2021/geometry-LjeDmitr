После выполнения данной команды исходники в репозитории будут отформатированы в соответствии с приложенным конфигом.
clang-format -i src/geometry/main.c src/libgeometry/format.c src/libgeometry/perim_area.c src/libgeometry/geometry.h

"git diff --exit-code" выведет в stdout изменения. Если исходники после автоматического форматирования отличаются от закоммиченных, то благодаря опции "--exit-code" команда завершится с ненулевым кодом и сборка не пройдет.
git diff --exit-code

Для сборки приложения достаточно команды
git clone https://github.com/trpo2021/geometry-LjeDmitr.git && cd geometry-LjeDmitr && make

Используйте команду make clean для удаления артефактов сборки.