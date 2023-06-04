#include <iostream>
#include <string>
#include <fstream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main() {
    std::string personal_profile;

    std::cout << "By Using GPT_Rizz you agree to Open AI and GPT_Rizz Terms of Service and Privacy Policy. Policy can be found on (LINK HERE)" << std::endl;

    std::cout << "Please declare location of your personal profile(we recommend using our template)";
    std::getline(std::cin, personal_profile);


    //file processing
    std::ifstream personal_profile_file(personal_profile);
    std::string personal_profile_file_content;

    //Error Checking
    if(personal_profile_file.is_open()){
        std::string line;
        while(std::getline(personal_profile_file, line)){
            personal_profile_file_content +=line + "\n";
        }
        personal_profile_file.close(); //read and store then close
    } else {
        std::cout<< "Error, Unable to open file make sure the file is in correct path and in supported format(txt)" << std::endl;
        return -1;
    }

    std::string Target_Profile_Path;
    std::cout << "Submit Target's Profile" << std::endl;
    std:cin>>Target_Profile_Path;

    tesseract::TessBaseAPI api;

    //OCR Error Handling
    if(api.Init(NULL,"eng", tesseract ::OEM_DEFAULT)){
        std::cout << "Error, Unable to initialize tesseract" << std::endl;
        return 1;
    }

    PIX *image = pixRead(Target_Profile_Path.c_str());
    if(image == nullptr) {
        std::cout << "Error, Unable to read image" << std::endl;
        return 1;
    }

    //Send to OCR
    api->SetImage(image);

    char* outText = api->GetUTF8Text();
    std:string result(out_txt);

    api->End();
    delete [] outText;

    return 0;
}
