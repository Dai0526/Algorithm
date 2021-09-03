#include "ReconBase.h"

class ReconAxial : public ReconBase{
public:
    ReconAxial(int slice, std::string& path) : ReconBase(slice, path) {}

protected:
    void SetGeomtryInfo() override {
        std::cout << "Step 4 (overrided): Set Geomtry for Axial Recon" << std::endl;
    }

    virtual void CreateAgent() {
        std::cout << "Step 5 (overrided): Create Agent" << std::endl;
        std::cout << "\tCreate Prep Agent" << std::endl;
        std::cout << "\tCreate Rebin Agent" << std::endl;
        std::cout << "\tCreate BP Agent" << std::endl;
        std::cout << "\tCreate Bone Correction Agent" << std::endl;
    };
};