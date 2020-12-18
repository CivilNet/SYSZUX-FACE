#include "syszux_face_retina.h"
#include "syszux_img2tensor.h"

using namespace deepvac;
class SyszuxFace{
    public:
        SyszuxFace(std::string path, std::string device = "cpu");
        SyszuxFace(const SyszuxFace&) = delete;
        SyszuxFace& operator=(const SyszuxFace&) = delete;
        SyszuxFace(SyszuxFace&&) = default;
        SyszuxFace& operator=(SyszuxFace&&) = default;
        virtual ~SyszuxFace() = default;

    public:
        std::vector<cv::Mat> process(cv::Mat frame);

    private:
        SyszuxFaceRetina detect_;
};