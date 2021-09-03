#include "ReconBase.h"
#include "ReconScout.h"
#include "ReconAxial.h"
#include "ReconHelical.h"


void rccRunRecon(ReconBase& recon){
    recon.RunRecon();
}

int main(){

    // Run Scout Recon
    std::cout << "\r\nRun Scout Recon" << std::endl;
    std::string scoutPath = "c:\\data\\scout\\";
    ReconScout scout(16, scoutPath);
    rccRunRecon(scout);

    // Run Axial Recon
    std::cout << "\r\nRun Axial Recon" << std::endl;
    std::string axialPath = "c:\\data\\axial\\";
    ReconAxial axial(16, axialPath);
    rccRunRecon(axial);

    // Run Helical Recon
    std::cout << "\r\nRun Helical Reocn" << std::endl;
    std::string helicalPath = "c:\\data\\helical\\";
    ReconHelical helical(16, helicalPath);
    rccRunRecon(helical);

    return 0;
}