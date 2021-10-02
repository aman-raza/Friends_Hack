#include "./terminal-io.h"

TerminalIO::TerminalIO() = default;

TerminalIO::~TerminalIO() = default;

int TerminalIO::ReadInt(std::string const &prompt) const
{
	this->PrintString(prompt);
	std::string input = this->ReadString();
	try { return std::stoi(input); } 
	catch (std::exception& e) { return -1; }
	return -1;
}

std::string TerminalIO::ReadString(std::string const &prompt) const
{
	this->PrintString(prompt);
	std::string value = "";
	std::getline(std::cin, value, '\n');
	return value;
}

void TerminalIO::PrintString(std::string const &message) const
{
	std::cout << message;
}

