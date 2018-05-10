var buyingInfo = [
  {name: 'Bakens', price: 2.0, quantity: 2},
  {name: 'Cheetos', price: 1.50, quantity: 1},
  {name: 'Doritos', price: 2.50, quantity: 3},
  {name: 'fritos', price: 3.75, quantity: 7},
  {name: 'Lays', price: 2.75, quantity: 4}
];

var money = [
  {name: 'penny', price: 1},
  {name: 'nikel', price: 5},
  {name: 'dime', price: 10},
  {name: 'quarter', price: 25},
  {name: 'dollar', price: 100}
];

var quarters = 0;
var dimes = 0;
var nikels = 0;
var pennys = 0;

var totalQuantity = [];
 totalQuantity[0] = buyingInfo[0].quantity;
 totalQuantity[1] = buyingInfo[1].quantity;
 totalQuantity[2] = buyingInfo[2].quantity;
 totalQuantity[3] = buyingInfo[3].quantity;
 totalQuantity[4] = buyingInfo[4].quantity;

 var coinPicture = [];
 coinPicture[0] = "coins/quarter.png";
 coinPicture[1] = "coins/dime.jpg";
 coinPicture[2] = "coins/five.png";
 coinPicture[3] = "coins/penny.jpg";

var pname = document.getElementsByClassName('name');
for(var i = 0; i < 5; i++){
  var nametext = pname[i].innerHTML = buyingInfo[i].name + " $" +
                 buyingInfo[i].price + "  [" + buyingInfo[i].quantity + "]";
}

var itemStr;
$('.items').on('click', function() {
  var index = $(this).index();
  itemStr = $('#order').html();
  if(buyingInfo[index].quantity != 0 && $('#toBuyItems').is(':empty')){
    buyingInfo[index].quantity--;
    $(this).children('p').html(buyingInfo[index].quantity + " Remaing");
    itemStr += buyingInfo[index].name + " $" + buyingInfo[index].price + "<br />";
    $('#order').html(itemStr);
    var orderTitle = "you have bougth " + "<br />" + buyingInfo[index].name +
    " Price $" + buyingInfo[index].price;
    $('#orderTitle').html(orderTitle);
  }
  if (buyingInfo[index].quantity == 0) {
    $(this).children('p').html("Sold Out!");
  }
});

var sameItemStr = $('#finish').children('p').html();
var sum = 0;
var onlyOneTime = true;
if(onlyOneTime == true){
  $('#finish').on('click', function() {
    if($('#toBuyItems').is(':empty')){
    for (var i = 0; i < buyingInfo.length; i++) {
      if (totalQuantity[i] != buyingInfo[i].quantity) {
          sameItemStr += "you have " + (totalQuantity[i] - buyingInfo[i].quantity) +
            " of " + buyingInfo[i].name + "<br />";
        }
        $('#toBuyItems').html(sameItemStr);
        //makin the sum to show prices for all items, to then pay.

        $('#owe').html(owe);//owe money paragraph, adding all money to pay.
        onlyOneTime = false;
        //if($)
      }
    }
    if($('#owe').is(':empty')){
      for (var i = 0; i < buyingInfo.length; i++) {
        sum += buyingInfo[i].price * (totalQuantity[i] - buyingInfo[i].quantity);
      }
      var showSum = "you owe this much $<span id='sum'>" + sum + "</span>";
      $('#owe').html(showSum);
    }
  });
}

$('#coinsBox').hide();
$('button').on('click', function() {
  $('#coinsBox').show();
});

//the coins problems.....
var pay = 0;
var change = 0;
$('.coins').on('click', function() {
  var index = $(this).index();
  pay += money[index].price;
  $('#pay').html(pay + " paid pennies");
  var newSum = $('#sum').text();

  var paytrue = ((pay/100) >= sum);
  if (paytrue) {
     change = (pay - (sum * 100));
    var changeStr = "Your change is: " + (change / 100);
    $('#owe').html(changeStr);
    $('#coinsBox').hide();
    $('#pay').hide();
  }

  if (change > 0) {
quarters = change/25;
dimes = (change%25)/10;
nikels = ((change%25)%10)/5;
pennys = (((change%25)%10)%5);

for (var i = 0; i < Math.floor(quarters); i++) {
  showCoinsChange(0);
}
for (var i = 0; i < Math.floor(dimes); i++) {
  showCoinsChange(1);
}
for (var i = 0; i < Math.floor(nikels); i++) {
  showCoinsChange(2);
}
for (var i = 0; i < Math.floor(pennys); i++) {
  showCoinsChange(3);
}
  }
});

var showCoinsChange = function(coin) {

  var div = document.getElementById('change');
  var quardiv = document.createElement('div');
  var imgquarters = document.createElement('img');
  var q = document.createAttribute('src');
  q.value = coinPicture[coin];
  imgquarters.setAttributeNode(q);
  quardiv.appendChild(imgquarters);
  div.appendChild(quardiv);
  var coinsClass = document.createAttribute('class');
  coinsClass.value = "changeCoins";
  imgquarters.setAttributeNode(coinsClass);
}
