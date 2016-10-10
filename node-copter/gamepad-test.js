var GamePad = require( 'node-gamepad' );
var controller = new GamePad( 'logitech/rumblepad2' );
controller.connect();
 
controller.on( 'left:move', function(e) {
	    console.log( e.x + ", " + e.y );
} );
controller.on( 'down:press', function() {
	    console.log( 'down' );
} );
