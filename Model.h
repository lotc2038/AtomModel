#pragma once
#include "GL.h"
#include <vector>
class Model
{
private: 
	int electronsCount;
	int orbitalsCount;
	std::vector<int>electronCfg;

public:
	Model() {}
	Model(int electrons) {
		this->electronsCount = electrons;
	}

	Model(int electrons, int orbitals, std::vector<int>Cfg) {
		this->electronsCount = electrons;
		this->orbitalsCount = orbitals;
		this->electronCfg = Cfg;
	}
	
	int period(int electrons);
	std::vector <int> electronCfgCalc(int electrons);
	void createModel(int electrons);
	void setElectronsCount(int electrons);
	void setElectronCfg(int e) { electronCfg.push_back(e); };

	int getElectronsCount() { return electronsCount; }
	int getOrbitalsCount() { return orbitalsCount; }
	std::vector <int> getElectronCfg() { return electronCfg; }
};

