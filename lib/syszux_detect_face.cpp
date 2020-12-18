#include "syszux_detect_face.h"
using namespace deepvac;
SyszuxFace::SyszuxFace(std::string path, std::string device):
    detect_(SyszuxFaceRetina(path, device)){}

std::vector<cv::Mat> SyszuxFace::process(cv::Mat frame){
    auto faces_opt = detect_.process(frame);
    if(!faces_opt){
        throw std::runtime_error("invalid input mat or internal error.");
    }
    return faces_opt.value();
}