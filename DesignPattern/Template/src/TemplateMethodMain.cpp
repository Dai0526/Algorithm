#include "ReconBase.h"
#include "ReconScout.h"
#include "ReconAxial.h"
#include "ReconHelical.h"


void rccRunRecon(ReconBase* recon){
    recon->RunRecon();
}

int main(){

    // Run Scout Recon
    std::cout << "\r\nRun Scout Recon" << std::endl;
    std::string scoutPath = "c:\\data\\scout\\";
    ReconScout scout(16, scoutPath);
    ReconScout* pScout = &scout;
    rccRunRecon(pScout);

    // Run Axial Recon
    std::cout << "\r\nRun Axial Recon" << std::endl;
    std::string axialPath = "c:\\data\\axial\\";
    ReconAxial axial(16, axialPath);
    ReconAxial* pAxial = &axial;
    rccRunRecon(pAxial);

    // Run Helical Recon
    std::cout << "\r\nRun Helical Reocn" << std::endl;
    std::string helicalPath = "c:\\data\\helical\\";
    ReconHelical helical(16, helicalPath);
    ReconHelical* pHelical = &helical;
    rccRunRecon(pHelical);

    return 0;
}