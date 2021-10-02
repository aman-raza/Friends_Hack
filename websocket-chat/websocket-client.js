const WS = new WebSocket('ws://localhost:3333')
var username

WS.onopen = ()=>{
  document.querySelector("#status").innerHTML = 'Chat Connected!'
}

WS.onclose = ()=>{
  document.querySelector("#status").innerHTML = 'Chat Disconnected!'
}

WS.onmessage = (payload)=>{
  displaymessages(payload.data)
}

function displaymessages(msg){
  let a = document.createElement('div')
  a.classList.add("w3-rest")
  let b = document.createElement('p')
  b.innerHTML = msg;
  a.appendChild(b)
  document.querySelector('#messenger').appendChild(a)
  //scroll to the bottom
  a.scrollIntoView()
}

document.getElementById('form0').onsubmit = function (){
  let input = document.getElementById('name').value
  // WS.send(input)
  username = `<b>${input}: </b>`
  document.getElementById('form0').style.display = 'none'
  document.getElementById('form1').style.display = 'block'
  let x = document.createElement('h3')
  x.innerHTML = input
  x.classList.add("w3-text-black")
  x.classList.add("w3-center")
  document.getElementById('header').appendChild(x)
}

document.getElementById('form1').onsubmit = function (){
  let input = document.getElementById('message')
  WS.send(username + input.value)
  input.value = ''
}
