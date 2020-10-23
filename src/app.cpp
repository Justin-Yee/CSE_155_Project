#include <server.h>
#include <Resistor.h>

using namespace ucm;

int main(int argc, char** argv){

    CrowServer server(argc, argv);

        Resistor* resist = new Resistor();

    server.renderHTML("/", "index.html");

        server.route("/handle", [&](const request& req, response& res){

        if (req.has_params({"band_1","band_2","band_3","band_4","band_5"})){
            
            std::string band1 = req.url_params.get("band_1");
            std::string band2 = req.url_params.get("band_2");
            std::string band3 = req.url_params.get("band_3");
            std::string band4 = req.url_params.get("band_4");
            std::string band5 = req.url_params.get("band_5");

            std::cout<<" Bands 1:"<<band1<<" 2:"<<band2<<" 3:"<<band3<<" 4:"<<band4<<" 5:"<<band5<<std::endl;
            
            json ans;
            if(band5 == ""){
                int num = resist->sigFig("0",band1,band2);
                std::string mul = resist->mult(band3);
                std::string tolerance = resist->tol(band4);
                ans["ans"] = resist->resistance(num,mul,tolerance);
            }
            else
            {// "num" +"mul"+ &Omega + tolerance + "%"
                int num = resist->sigFig(band1,band2,band3);
                std::string mul = resist->mult(band4);
                std::string tolerance = resist->tol(band5);
                ans["ans"] = resist->resistance(num,mul,tolerance);
            }
            res.sendJSON(ans);
        }

        else{
            res.sendError400();
        }
    });

    server.run();
}
