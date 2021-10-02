function load_images(){

  enemy_image=new Image;
  enemy_image.src="data/v1.png";

  gem_image=new Image;
  gem_image.src="data/gem.png";

  fighter_image=new Image;
  fighter_image.src= "data/superhero.png";

}

function init(){
  //preparing canvas and 2d context
  canvas=document.getElementById("mcanvas");
  W=700; canvas.width=W;
  H=400; canvas.height=H;

  pen =canvas.getContext('2d');

  game_over=false;//game check

  //defining objects;
  e1={
    x:150,
    y:100,
    w:60,
    h:60,
    speed:20,
  };
  e2={
    x:315,
    y:175,
    w:60,
    h:60,
    speed:30,
  };
  e3={
    x:450,
    y:300,
    w:60,
    h:60,
    speed:40,
  };

  enemy=[e1,e2,e3];

  fighter={
    x:20,
    y:H/2,
    w:60,
    h:60,
    speed:20,
    moving:false,
    health:100,
  };
  gem={
    x:W-100,
    y:H/2,
    w:60,
    h:60,
  };

  //Adding Event listener
   canvas.addEventListener('mousedown',function(){
     fighter.moving=true;
     console.log("mouse pressed");
   });
   canvas.addEventListener('mouseup',function(){
     fighter.moving=false;
     console.log("mouse Released");
   });

}

function isTouching(rect1,rect2){

  if(rect1.x<rect2.x+rect2.w && rect1.x+rect1.w>rect2.x &&
  rect1.y<rect2.y+rect2.h && rect1.y+rect1.h>rect2.y){
    return true
  }
  return false;

}

function draw(){
  //clearing frame
  pen.clearRect(0,0,W,H);
  //draw gem and fighter_image
  pen.drawImage(fighter_image,fighter.x,fighter.y,fighter.w,fighter.h);
  pen.drawImage(gem_image,gem.x,gem.y,gem.w,gem.h);
  //enemy images
  for(let i=0;i<enemy.length;i++){
    pen.drawImage(enemy_image,enemy[i].x,enemy[i].y,enemy[i].w,enemy[i].h);
  }
  //Score
  pen.fillStyle="white";
  pen.fillText("Score "+fighter.health,10,10);
}

function update(){
  //fighter move
  if(fighter.moving==true){
    fighter.x+=fighter.speed;
    fighter.health+=20;
  }

  for(var i =0 ;i<enemy.length;i++){
    if(isTouching(enemy[i],fighter)){
      fighter.health-=50;
      if(fighter.health<0){
        game_over=true;
        alert(" Game Over Your Score: " + fighter.health);
      }
    }
  }

  if(isTouching(fighter,gem)){
    game_over=true;
    alert("You Won and Survived!");
    return ;
  }

  for(var i=0;i<enemy.length;i++){
    enemy[i].y+=enemy[i].speed;
    if(enemy[i].y>H-enemy[i].h || enemy[i].y<0){
      enemy[i].speed *= -1;
    }
  }
}

function gameloop(){

  if(game_over==true){
    clearInterval(t);
  }
  draw();
  update();
  console.log("inside loop");

}

load_images();
init();
t = setInterval(gameloop,100);
