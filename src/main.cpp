#include "syszux_detect_face.h"
#include "syszux_img2tensor.h"

using namespace deepvac;
int main(int argc, const char* argv[]) {
    if (argc != 3) {
        std::cout<<"Usage: "<<argv[0]<<"<weights_path> <img_path>"<<std::endl;
        return -1;
    }

    std::string weights_path = argv[1];
    std::string img_path = argv[2];
    SyszuxFace face_detect(weights_path);
    
    auto mat_opt = gemfield_org::img2CvMat(img_path);
    if(!mat_opt){
        throw std::runtime_error("illegal image detected");
        return 1;
    }
    auto mat_out = mat_opt.value();
    auto detect_out = face_detect.process(mat_out);

    std::cout<<"SyszuxFace Detected face num: "<<detect_out.size()<<std::endl;

    for (int i=0; i<detect_out.size(); i++){
        cv::imwrite("./syszux_face_"+std::to_string(i)+".jpg", detect_out[i]);
    }
    return 0;
}