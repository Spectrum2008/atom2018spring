var buyingInfo = [
  {name: 'Bakens', price: 2.0, quantity: 2},
  {name: 'Cheetos', price: 1.50, quantity: 0},
  {name: 'Doritos', price: 2.50, quantity: 3},
  {name: 'fritos', price: 3.75, quantity: 5},
  {name: 'Lays', price: 2.75, quantity: 1}
];

var shoppIndexes = [];

var wolesale = "";
var itemStr;
$('.items').on('click', function() {//ask teacher why it doesnt works with shorthand sintax
var index = $(this).index();
itemStr = $('#order').html();
  itemStr += buyingInfo[index].string + " $" + buyingInfo[index].price + "<br />";
  $('#order').html(itemStr);
wolesale += itemStr;
console.log(itemStr);
});
