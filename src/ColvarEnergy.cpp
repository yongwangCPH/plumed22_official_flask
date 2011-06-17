#include "Colvar.h"
#include "ActionRegister.h"
#include "PlumedMain.h"

#include <string>
#include <cmath>
#include <cassert>

namespace PLMD{

//+PLUMEDOC COLVAR ENERGY
/**
Potential energy of the system. Example:
\verbatim
ENERGY LABEL=energy
\endverbatim

\bug It does not work with variable cell simulations. Should include also PV contribution.

*/
//+ENDPLUMEDOC


class ColvarEnergy : public Colvar {
  bool components;

public:
  ColvarEnergy(const ActionOptions&);
// active methods:
  virtual void calculate();
};


using namespace std;


PLUMED_REGISTER_ACTION(ColvarEnergy,"ENERGY")

ColvarEnergy::ColvarEnergy(const ActionOptions&ao):
PLUMED_COLVAR_INIT(ao),
components(false)
{
  std::vector<int> atoms;
  requestAtoms(atoms);
  isEnergy=true;
  addValueWithDerivatives("");
  getValue("")->setPeriodicity(false);
}


// calculator
void ColvarEnergy::calculate(){
  setValue(plumed.getAtoms().getEnergy());
}

}



