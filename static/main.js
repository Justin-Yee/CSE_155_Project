$(document).ready(function(){
	$("#submit_4").click(function() {
        /*var band_1 = $("#band_1").val();
        var band_2 = $("#band_2").val();
        var band_3 = $("#band_3").val();
        var band_4 = $("#band_4").val();
        alert(band_1 + " "+ band_2+" "+ band_3+ " "+ band_4+ " ");*/
        alert("alert");
        $.get("/handle",{"band_1": $("#band_1").val(),"band_2":$("#band_2").val(),"band_3": $("#band_3").val(),"band_4": $("#band_4").val(),"band_5": null}, function(response){
            var ans = JSON.parse(response);
            if(ans["ans"] == "Invalid")
                alert("Band 4 is Invalid Color");

            $("#sol").html(ans["ans"]);

        });
    });

    $("#submit_5").click(function() {
        /*var band_1 = $("#band_1").val();
        var band_2 = $("#band_2").val();
        var band_3 = $("#band_3").val();
        var band_4 = $("#band_4").val();
        var band_5 = $("#band_5").val();*/
        
        $.get("/handle",{"band_1": $("#band_1").val(),"band_2":$("#band_2").val(),"band_3": $("#band_3").val(),"band_4": $("#band_4").val(),"band_5": $("#band_5").val()}, function(response){
        var ans = JSON.parse(response);
        if(ans["ans"] == "Invalid")
            alert("Band 5 is Invalid Color");
        //console.log(ans["ans"]);

        $("#sol").html(ans["ans"]);
         });
    });
});
