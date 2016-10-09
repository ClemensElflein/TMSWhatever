var arDrone = require('ar-drone');
var client  = arDrone.createClient();
var GamePad = require( 'node-gamepad' );
var controller = new GamePad( 'logitech/rumblepad2' );
controller.connect();

var state = 0;

// start, land
controller.on('4:press', function() {
	if(state == 0) {
		state = 1;
		client.takeoff();
	} else {
		state = 0;
		client.land();
	}
});

// pitch, yaw
controller.on('left:move', function(e) {
	var yaw = (e.x-128)/128;
	var pitch = (e.y-128)/128;
	if(yaw >= 0) {
		client.clockwise(yaw);
	} else {
		client.counterClockwise(-yaw);
	}

	if(pitch >= 0) {
		client.down(pitch);
	} else {
		client.up(-pitch);
	}
});

// nick, roll
controller.on('right:move', function(e) {
	var roll = (e.x-128)/128;
	var nick = -(e.y-128)/128;
	if(nick >= 0) {
		client.front(nick);
	} else {
		client.back(-nick);
	}

	if(roll >= 0) {
		client.right(roll);
	} else {
		client.left(-roll);
	}
});


/*
client.takeoff();

client
  .after(5000, function() {
	      this.front(0.5);
	 })
  .after(3000, function() {
	      this.stop();
	          this.land();
		    });
		    */
