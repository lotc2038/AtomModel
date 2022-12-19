#include "Model.h"

int Model::period(int electrons)
{
	int orbitalsCount;
	std::vector<int>period = { 1, 3, 11, 19, 37, 55, 87 };
	for (int i = 0; i < 7; i++) {
		if (electrons >= period[i]) {
			orbitalsCount++;
		}
		else return orbitalsCount;
	}
	return orbitalsCount;
}

std::vector <int> Model::electronCfgCalc(int electrons)
{
	const int s = 2, p = 8, d = 18, f = 32;
	
	std::vector<int>maxElectronCfg = { s, p, d, f, d, p, s };
	std::vector<int>el{ 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < 7; i++) {
		while (electrons > 0) {
			if (el[i] < maxElectronCfg[i]) {
				setElectronCfg(el[i]++);
			}

			else {
				break;
			}
			electrons--;
		}

	}

	return el;
}

void Model::createModel(int electrons)
{
	drawInit(electrons, period(electrons), electronCfgCalc(electrons));
}




