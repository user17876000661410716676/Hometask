MAIN="menu_fragments.cpp functiones.cpp main.cpp"
APP=example

if [ ! -f $APP ]; then rm $APP
fi

g++ $MAIN -o $APP

./$APP
