$(document).ready(function() {
  $('#navbar li a').hover(
      function () {
          $(this).stop().animate({backgroundColor:'#fa8b18'}, 300);
          }, function () {
          $(this).stop().animate({backgroundColor:'#db7002'}, 100);
      });

   $('#navbar h1 a').hover(
      function () {
          $(this).stop().animate({backgroundColor:'#000000'}, 300);
          }, function () {
          $(this).stop().animate({backgroundColor:'#636363'}, 100);
      });

    $('#block-vsite_menus-1 ul.menu li a').hover(
      function () {
          $(this).stop().animate({backgroundColor:'#F58714'}, 300);
          }, function () {
          $(this).stop().animate({backgroundColor:'#ffffff'}, 100);
      });

    $('#block-scholar_biocv-bio_blurb a').attr("href","#");

    var container = $("#node-3793");
    $("#block-scholar_biocv-bio_blurb a").click(function(event){

      if (container.is(".open")) {
        container.removeClass("open").animate({
        height:'0'},"1500");

       } else {
      container.addClass("open").animate({
      height:'70%'},"1500");
      }

     });

  });