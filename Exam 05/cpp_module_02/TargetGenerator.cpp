#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	std::vector<ATarget*>::iterator ite = this->types.end();
	for (std::vector<ATarget*>::iterator it = this->types.begin(); it != ite; ++it)
		delete *it;
	this->types.clear();
}

void TargetGenerator::learnTargetType(ATarget *type) {
	if (type) {
		std::vector<ATarget*>::iterator ite = this->types.end();
		for (std::vector<ATarget*>::iterator it = this->types.begin(); it != ite; ++it)
			if ((*it)->getType() == type->getType())
				return ;
		this->types.push_back(type->clone());
	}
}

void TargetGenerator::forgetTargetType(std::string const &name) {
	std::vector<ATarget*>::iterator ite = this->types.end();
	for (std::vector<ATarget*>::iterator it = this->types.begin(); it != ite; ++it) {
		if ((*it)->getType() == name) {
			delete *it;
			it = this->types.erase(it);
		}
	}
}

ATarget *TargetGenerator::createTarget(std::string const &name) {
	std::vector<ATarget*>::iterator ite = this->types.end();
	for (std::vector<ATarget*>::iterator it = this->types.begin(); it != ite; ++it) {
		if ((*it)->getType() == name) {
			return (*it);
		}
	}
	return (nullptr);
}
