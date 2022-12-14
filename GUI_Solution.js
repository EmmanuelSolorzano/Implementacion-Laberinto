let solution;
let problem;

function preload() {
  solution = loadTable('GUI_CSV/solution.csv', 'csv');
  problem = loadTable('GUI_CSV/problem.csv', 'csv');
}

function graphicLabyrinth(problem,solution,startactualPosX,pos,squareSize,separation,ignoreSolution){
  for (let r = 0; r < problem.getRowCount(); r++){
    for (let c = 0; c < problem.getColumnCount(); c++) {
      if(problem.getString(r, c) == "0"){
        fill(1);           
      }
      else if(problem.getString(r, c) == "2"){
        fill(0, 255, 0);
      }
      else{
        if((solution.getString(r, c) == "1") && (ignoreSolution == 0)){
          fill(0, 206, 209);
        }
        else{
          fill(127, 63, 120);
        }      
      }
      stroke(127, 63, 120);
      rect(pos[0], pos[1], squareSize[0], squareSize[1]);   
      pos[0] += separation;
    }
    pos[0] = startactualPosX;
    pos[1] += separation;
  }
}

function setup() { 
  createCanvas(1380,770);
  background(220, 220, 220);

  let ignoreSolution = 0;

  let startactualPosX = 750;
  let startPosY = 40;
  let pos = [startactualPosX,startPosY];
  let squareSize = [40,40];
  let separation = 40;  
  graphicLabyrinth(problem,solution,startactualPosX,pos,squareSize,separation,ignoreSolution);

  ignoreSolution++;
  startactualPosX = 50;
  startPosY = 40;
  pos = [startactualPosX,startPosY];
  squareSize = [40,40];
  separation = 40;  
  graphicLabyrinth(problem,problem,startactualPosX,pos,squareSize,separation,ignoreSolution);
}