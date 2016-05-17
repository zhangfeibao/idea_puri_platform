package com.midea.william.ui
{
	import flash.display.Sprite;
	import flash.events.MouseEvent;
	
	public class ConnectWire extends Sprite
	{
		private var _pin:Pin;
		private var _port:DevicePort;

		public function ConnectWire(dp:DevicePort)
		{
			_port = dp;
		}
		
		public function set pin(p:Pin):void
		{
			_pin = p;
		}
		
		public function get pin():Pin
		{
			return _pin;
		}
		
		public function set port(p:DevicePort):void
		{
			_port = p;
		}
		
		public function get port():DevicePort
		{
			return _port;
		}
		
		public function refresh(event:MouseEvent):void
		{
			this.graphics.clear();
			this.graphics.lineStyle(2,0xcc4488);
			this.graphics.moveTo(this.port.x,this.port.y);
			this.graphics.lineTo(event.localX,event.localY);
		}

	}
	
}
