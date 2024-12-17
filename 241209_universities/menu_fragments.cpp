#include "menu_fragments.hpp"
#include "functiones.hpp"

#include <iostream>

const str::MenuItem str::BACK = {
	"0 - Go back", str::back, &str::INFO
};
const str::MenuItem str::SPBSU = {
	"1 - SPBSU", str::spbsu, &str::INFO
};
const str::MenuItem str::ITMO = {
	"2 - ITMO university", str::itmo, &str::INFO
};
const str::MenuItem str::SPBPU = {
	"3 - Peter the Great St. Petersburg Polytechnic University", str::spbpu, &str::INFO
};
const str::MenuItem str::LETI = {
	"4 - Saint Petersburg Electrotechnical University", str::leti, &str::INFO
};

namespace {
	const str::MenuItem* info_children[] = {
		&str::BACK,
		&str::SPBSU,
		&str::ITMO,
		&str::SPBPU,
		&str::LETI
	};
	const int info_size = sizeof(info_children) / sizeof(info_children[0]);
}

const str::MenuItem str::EXIT = {
	"0 - Exit", str::exit, &str::MAIN 
};
const str::MenuItem str::INFO = {
	"1 - Learn more about Universities", str::menu, &str::MAIN, info_children, info_size 
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