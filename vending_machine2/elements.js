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

var totalQuantity = [];
 totalQuantity[0] = buyingInfo[0].quantity;
 totalQuantity[1] = buyingInfo[1].quantity;
 totalQuantity[2] = buyingInfo[2].quantity;
 totalQuantity[3] = buyingInfo[3].quantity;
 totalQuantity[4] = buyingInfo[4].quantity;

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
//the coins problems.....
var pay = 0;

$('.coins').on('click', function() {
  var index = $(this).index();
  pay += money[index].price;
  console.log(pay);
  if ($('#owe').is(':empty')) {
    console.log("owe is empty");
  }
  var newSum = $('#sum').text();

  console.log(pay/100);
  console.log(sum);
  var paytrue = ((pay/100) >= sum);
  if (paytrue) {
    var change = (pay - (sum * 100));
    var changeStr = "Your change is: " + (change / 100);
    $('#owe').html(changeStr);
  }

  if (true) {}
});

