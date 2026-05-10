#pragma once
#include <string>

using std::string;

class VALError {
public:
	VALError(string message) : message(message) {}
	const string& get_Message() const noexcept {
		return message;
	}
private:
	string message;
};


class ValidationError : public VALError {
public:
	ValidationError(string message) : VALError(message) {}
};