<!标题/>
<script>document.addEventListener('visibilitychange',function(){if(document.visibilityState=='hidden'){normal_title=document.title;
document.title='暗中观察~(๑Ő௰Ő๑)';
    }else{document.title=normal_title;
    }
});
</script>

<!访客人数/>
<b href="https://info.flagcounter.com/jbd8"><img src="https://s01.flagcounter.com/count2/jbd8/bg_FFFFFF/txt_000000/border_CCCCCC/columns_2/maxflags_10/viewers_0/labels_1/pageviews_1/flags_0/percent_0/" alt="Flag Counter" border="0"></b>

<!雪花/>
<script>
function randomColor() {
    return (
    "rgb(" +
    ~~(Math.random() * 255) +
    "," +
    ~~(Math.random() * 255) +
    "," +
    ~~(Math.random() * 255) +
    ")"
    );
}
  (function($) {
    $.fn.snow = function(options) {
        
      var $flake = $('<div id="flake" />')
          .css({ position: "absolute", top: "-50px"
        })
          .html("&#10052;"),
        documentHeight = $(document).height(),
        documentWidth = $(document).width(),
        defaults = {
          minSize: 10,
          maxSize: 20,
          newOn: 500,
          flakeColor: randomColor()
        },
        options = $.extend({}, defaults, options);
      var interval = setInterval(function() {
        var startPositionLeft = Math.random() * documentWidth - 100,
          startOpacity = 0.5 + Math.random(),
          sizeFlake = options.minSize + Math.random() * options.maxSize,
          endPositionTop = documentHeight - 40,
          endPositionLeft = startPositionLeft - 100 + Math.random() * 200,
          durationFall = documentHeight * 10 + Math.random() * 5000;
        $flake
          .clone()
          .appendTo("body")
          .css({
            left: startPositionLeft,
            opacity: startOpacity,
                "font-size": sizeFlake,
            color: options.flakeColor
            })
          .animate(
            { top: endPositionTop, left: endPositionLeft, opacity: 0.1
            },
            durationFall,
            "linear",
            function() {
              $(this).remove();
            }
          );
        }, options.newOn);
    };
})(jQuery);
  $.fn.snow({ minSize: 5, maxSize: 50, newOn: 1000, flakeColor: randomColor()
});
</script>

<!添加图片/>
<div align="center">
    <img src="http://images.cnblogs.com/cnblogs_com/37kiazz73/1420648/o_%E4%BB%93%E9%BC%A01.gif">
</div>
<!-- 为页面添加爱心特效 -->
<script type="text/javascript">

(function(window,document,undefined){
    var hearts = [];
    
    window.requestAnimationFrame = (function(){
        return window.requestAnimationFrame || 
        window.webkitRequestAnimationFrame ||
        window.mozRequestAnimationFrame ||
         window.oRequestAnimationFrame ||
         window.msRequestAnimationFrame ||
         function (callback){
             setTimeout(callback,
            1000/60);
        }
    })();
    
    init();

    function init(){
        css(".heart{width: 10px;height: 10px;position: fixed;background: #f00;transform: rotate(45deg);-webkit-transform: rotate(45deg);-moz-transform: rotate(45deg);}.heart:after,.heart:before{content: '';width: inherit;height: inherit;background: inherit;border-radius: 50%;-webkit-border-radius: 50%;-moz-border-radius: 50%;position: absolute;}.heart:after{top: -5px;}.heart:before{left: -5px;}");
        attachEvent();
        gameloop();
    }

    function gameloop(){
        for(var i=0;i<hearts.length;i++){
            if(hearts[i
            ].alpha <=0){
                document.body.removeChild(hearts[i
                ].el);
                hearts.splice(i,
                1);
                continue;
            }

             hearts[i
            ].y--;
             hearts[i
            ].scale += 0.004;
             hearts[i
            ].alpha -= 0.013;
             hearts[i
            ].el.style.cssText = "left:"+hearts[i
            ].x+"px;top:"+hearts[i
            ].y+"px;opacity:"+hearts[i
            ].alpha+";transform:scale("+hearts[i
            ].scale+","+hearts[i
            ].scale+") rotate(45deg);background:"+hearts[i
            ].color;
        }

        requestAnimationFrame(gameloop);
    }

    function attachEvent(){
        var old = typeof window.onclick==="function" && window.onclick;
        window.onclick = function(event){
            old && old();
            createHeart(event);
        }
    }

    function createHeart(event){
        var d = document.createElement("div");
        d.className = "heart";
        hearts.push({
            el : d,
            x : event.clientX - 5,
            y : event.clientY - 5,
            scale : 1,
            alpha : 1,
            color : randomColor()
        });

        document.body.appendChild(d);
    }

    function css(css){
        var style = document.createElement("style");
        style.type="text/css";
        try{
            style.appendChild(document.createTextNode(css));
        }
        catch(ex){
            style.styleSheet.cssText = css;
        }

        document.getElementsByTagName('head')[
            0
        ].appendChild(style);
    }

    function randomColor(){
        return "rgb("+(~~(Math.random()*255))+","+(~~(Math.random()*255))+","+(~~(Math.random()*255))+")";
    }
})(window,document);
</script>