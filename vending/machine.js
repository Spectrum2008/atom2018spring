var images = [
    { photo: './images/Baken.jpg', name: 'Baken ', price: '2.00', Quantity: '[5] ' },
    { photo: './images/cheetos.png', name: 'Cheetos ', price: '2.98', Quantity: '[2] ' },
    { photo: './images/cheez.jpg', name: 'cheez it', price: '2.50', Quantity: '[3] ' },
    { photo: './images/Doritos.jpg', name: 'Doritos ', price: '2.98', Quantity: '[0] ' },
    { photo: './images/Lays.jpg', name: 'Lays ', price: '1.50', Quantity: '[8] ' }
];

var displayBox = document.getElementById("displayBox");
//var allDivs = document.getElementsByClassName("leftdivs");

for (let i = 0; i < 5; i++) {
    //making div to append
    var toAppendDiv = document.createElement("div");
    //appending div to the left box
    displayBox.appendChild(toAppendDiv);
    //getting the first element so we don't do to all, all time.
    var createdDiv = displayBox.getElementsByTagName("div")[i];
  
    //creathing img attibute
    var createdImg = document.createElement("img");
    createdDiv.appendChild(createdImg);
   
    var productNames = document.createTextNode(images[i].Quantity + images[i].name + images[i].price);
    displayBox.appendChild(productNames);

    var createdSrc = document.createAttribute("src");
    createdSrc.value = images[i].photo;
    createdImg.setAttributeNode(createdSrc);

    var attImgClass = document.createAttribute("class");
    attImgClass.value = "displayBoxImg";
    createdImg.setAttributeNode(attImgClass);

    var attDivClass = document.createAttribute("class");
    attDivClass.value = "displayBoxDivs";
    createdDiv.setAttributeNode(attDivClass);
}




$(".displayBoxDivs").on("click", () => {
     console.log($(this).text());
    
});



//teacher i want to change an image to say there is no more.