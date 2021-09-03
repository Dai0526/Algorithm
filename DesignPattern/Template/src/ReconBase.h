#pragma once

#include <iostream>

class ReconBase {

public:
    ReconBase(int slice, std::string& path) : m_nSlice(slice), m_path(path) {}

    void ReconBase::RunRecon() {
        this->LoadScanParameter();
        this->LoadConfiguration();
        this->LoadData();
        this->SetGeomtryInfo();
        this->CreateAgent();
        this->Reconstruct();
        this->SaveImages();
    }

protected:

    void ReconBase::LoadScanParameter() {
        std::cout << "Step 1: Loaded Scan Parameters" << std::endl;
    }

    void ReconBase::LoadConfiguration() {
        std::cout << "Step 2: Loaded Configuration" << std::endl;
    }

    void ReconBase::LoadData() {
        std::cout << "Step 3: Loaded Data" << std::endl;
    }

    virtual void ReconBase::SetGeomtryInfo() = 0;

    virtual void ReconBase::CreateAgent() {
        std::cout << "Step 5: Create Agent" << std::endl;
        std::cout << "\tCreate Prep Agent" << std::endl;
        std::cout << "\tCreate Rebin Agent" << std::endl;
        std::cout << "\tCreate BP Agent" << std::endl;
    };

    void ReconBase::Reconstruct() {
        std::cout << "Step 6: Start Agent to do Reconstruction" << std::endl;
    }

    void ReconBase::SaveImages() {
        std::cout << "Step 7: Image Saved" << std::endl;
    }

protected:
    int m_nSlice = 0;
    std::string m_path = "";

};