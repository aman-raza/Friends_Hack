
 var a= document.getElementById("p1");
 var b= document.querySelector("#p2");
 var p1score=0;
 var c= document.querySelector("h1");
 var d= document.querySelector("#p1display");
 var e= document.querySelector("#p2display");
 var p2score=0;
 var gameover = false;
 var winningscore=5;
 var f = document.getElementById("p3");
 var g= document.querySelector("p span");
 var numinput = document.querySelector("input");

 a.addEventListener("click",function(){
 	if(!gameover){
 	p1score++; 
 	if(p1score == winningscore){
 		p1display.classList.add("winner");
 		console.log("gameover!!");
 		gameover=true;
 	}
 	
 	p1display.textContent=p1score;
 	}
 });
 
 b.addEventListener("click",function(){
 	if(!gameover){
 		p2score++;
 	if(p2score == winningscore){
 		p2display.classList.add("winner");
 		console.log("gameover!!");
 		gameover=true;
 	}
 	p2display.textContent=p2score;
 	}
 	
 });

 f.addEventListener("click",function(){
 	p1score=0;
 	p2score=0;
 	p1display.textContent=0;
 	p2display.textContent=0;
 	p1display.classList.remove("winner");
 	p2display.classList.remove("winner");
 	gameover =false;
 });


 function reset(){
 	p1score=0;
 	p2score=0;
 	p1display.textContent=0;
 	p2display.textContent=0;
 	p1display.classList.remove("winner");
 	p2display.classList.remove("winner");
 	gameover =false;

 }

numinput.addEventListener("change",function(){
	scoreboard.textContent = numinput.value;
	winningscore=Number(numinput.value);
	reset();
});