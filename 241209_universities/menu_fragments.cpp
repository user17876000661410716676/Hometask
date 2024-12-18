#include "menu_fragments.hpp"
#include "functiones.hpp"

#include <iostream>

const str::MenuItem str::SPBSU_CONTROL_PROCESSES = {
	"1 - Факультет Прикладной Математики - Процессов Управления", str::spbsu_control_processes, &str::INFO_SPBSU
};
const str::MenuItem str::SPBSU_MATH_MECH = {
	"2 - Математико-Механическом факультет", str::spbsu_math_mech, &str::INFO_SPBSU
};
const str::MenuItem str::SPBSU_LINGUISTICS = {
	"3 - Факультет Лингвистики", str::spbsu_linguistics, &str::INFO_SPBSU
};
const str::MenuItem str::SPBSU_BACK = {
	"0 - Назад", str::spbsu_back, &str::INFO_SPBSU
};

namespace {
	const str::MenuItem* spbsu_children[] = {
		&str::SPBSU_BACK,
		&str::SPBSU_CONTROL_PROCESSES,
		&str::SPBSU_MATH_MECH,
		&str::SPBSU_LINGUISTICS,
	};
	const int spbsu_size = sizeof(spbsu_children) / sizeof(spbsu_children[0]);
}

const str::MenuItem str::INFO_BACK = {
	"0 - Выйти в главное меню", str::info_back, &str::INFO
};
const str::MenuItem str::INFO_SPBSU = {
	"1 - СПБГУ", str::menu, &str::INFO, spbsu_children, spbsu_size
};
const str::MenuItem str::INFO_ITMO = {
	"2 - ИТМО", str::info_itmo, &str::INFO
};
const str::MenuItem str::INFO_SPBPU = {
	"3 - Политех", str::info_spbpu, &str::INFO
};
const str

::MenuItem str::INFO_LETI = {
	"4 - ЛЭТИ", str::info_leti, &str::INFO
};

namespace {
	const str::MenuItem* info_children[] = {
		&str::INFO_BACK,
		&str::INFO_SPBSU,
		&str::INFO_ITMO,
		&str::INFO_SPBPU,
		&str::INFO_LETI
	};
	const int info_size = sizeof(info_children) / sizeof(info_children[0]);
}

const str::MenuItem str::EXIT = {
	"0 - Я уже студент", str::exit, &str::MAIN 
};
const str::MenuItem str::INFO = {
	"1 - Посмотреть университеты Санкт-Петербурга", str::menu, &str::MAIN, info_children, info_size 
};
namespace {
	const str::MenuItem* main_children[] = {
		&str::EXIT,
		&str::INFO
	};
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const str::MenuItem str::MAIN = {
	nullptr, str::menu, nullptr, main_children, main_size
};