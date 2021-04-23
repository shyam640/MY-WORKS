showTasks();
let addBtn = document.getElementById('addBtn');
addBtn.addEventListener("click",function(e){
   e.preventDefault();
   let titletxt = document.getElementById('titleTxt');
   let addtxt = document.getElementById('addTxt');
   let tasks = localStorage.getItem('tasks');
   if(tasks == null)
      tasksObj = [];
   else
      tasksObj = JSON.parse(tasks);
   let ttlTxtObj = {
      title: titletxt.value,
      text: addtxt.value
   }
   tasksObj.push(ttlTxtObj);
   localStorage.setItem('tasks', JSON.stringify(tasksObj));
   titletxt.value = "";
   addTxt.value = "";
   
   showTasks();
});

function showTasks(){
   let tasks = localStorage.getItem('tasks');
   if(tasks == null)
      tasksobj = [];
   else
      tasksobj = JSON.parse(tasks);
   let html = "";
   tasksobj.forEach(function(element,index){
      html += `<div id="taskCard${index}" class="taskCard my-3 mx-3 card" style="width:18rem">
      <div class="card-body">
         <h5 class="card-title">Task ${index+1}</h5>
         <h6>${element.title}</h6>
         <p class="card-text">${element.text}</p>
         <div class="col-0 my-2">
            <button class="btn btn-primary" type="button" id="mark" onclick="mark()">Mark As Important</button>
         </div>
         <button id="${index}" onclick="deleteNode(this.id)" class="btn btn-primary">Delete Task</button>
      </div>
   </div>`;
   });
   let tasksElm = document.getElementById('tasks');
   if(tasksobj.length != 0)
      tasksElm.innerHTML = html;
   else
      tasksElm.innerHTML = `No Task has been added yet`;
   
}

function mark(){
   
}


function deleteNode(index){
   let tasks = localStorage.getItem('tasks');
   if(tasks == null)
      tasksobj = [];
   else
      tasksobj = JSON.parse(tasks);
   tasksobj.splice(index,1);
   localStorage.setItem('tasks',JSON.stringify(tasksobj));
   showTasks();
}

let search = document.getElementById('searchTxt');
search.addEventListener('input',function(){
   let inputTxt = search.value.toLowerCase();
   let taskCard = document.getElementsByClassName('taskCard');
   Array.from(taskCard).forEach(function(element){
      let taskCardTxt = element.getElementsByTagName('p')[0].innerText;
      let taskCardTitle = element.getElementsByTagName('h6')[0].innerText;
      if(taskCardTxt.includes(inputTxt) || taskCardTitle.includes(inputTxt))
         element.style.display = 'block';
      else
         element.style.display = 'none';
   })
});