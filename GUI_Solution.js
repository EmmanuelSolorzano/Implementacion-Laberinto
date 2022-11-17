// Given the following CSV file called "mammals.csv"
// located in the project's "assets" folder:
//
// id,species,name
// 0,Capra hircus,Goat
// 1,Panthera pardus,Leopard
// 2,Equus zebra,Zebra

let table;

function preload() {
  //my table is comma separated value "csv"
  //and has a header specifying the columns labels
  table = loadTable('data.csv', 'csv', 'header');
  //the file can be remote
  //table = loadTable("http://p5js.org/reference/assets/mammals.csv",
  //                  "csv", "header");
}

function setup() {
  createCanvas(960,540);
  background(220);
}


STARTPOSX = 40;
STARTPOSY = 40;

function draw(){
  

  for (let r = 0; r < table.getRowCount(); r++){
    for (let c = 0; c < table.getColumnCount(); c++) {
      if(table.getString(r, c) == '0'){
        fill(1);
        stroke(127, 63, 120);
        rect(STARTPOSX, STARTPOSY, 40, 40);
        STARTPOSX+=60;
      }     
    }
    STARTPOSX = 40;
    STARTPOSY+=60;
  }
  
}