let solution;
let problem;

function preload() {
  solution = loadTable('solution.csv', 'csv');
  problem = loadTable('problem.csv', 'csv');
}



function graphicLabyrinth(table){
  for (let r = 0; r < table.getRowCount(); r++){
    for (let c = 0; c < table.getColumnCount(); c++) {
      if(table.getString(r, c) == "0"){
        fill(1);
        stroke(127, 63, 120);
        rect(POS[0], POS[1], SQUARESIZE[0], SQUARESIZE[1]);      
      }     
      else{
        fill(127, 63, 120);
        stroke(127, 63, 120);
        rect(POS[0], POS[1], SQUARESIZE[0], SQUARESIZE[1]);
      }
      POS[0] += SEPARATION;
    }
    POS[0] = STARTPOSX;
    POS[1] += SEPARATION;
  }
}




function setup() { 
  createCanvas(1380,770);
  background(220);

  STARTPOSX = 740;
  STARTPOSY = 40;
  POS = [STARTPOSX,STARTPOSY];
  SQUARESIZE = [40,40];
  SEPARATION = 40;  
  graphicLabyrinth(solution,STARTPOSX,STARTPOSY,POS,SQUARESIZE,SEPARATION);

  STARTPOSX = 40;
  STARTPOSY = 40;
  POS = [STARTPOSX,STARTPOSY];
  SQUARESIZE = [40,40];
  SEPARATION = 40;  
  graphicLabyrinth(problem,STARTPOSX,STARTPOSY,POS,SQUARESIZE,SEPARATION);
}



/*
function draw(){
  
}*/