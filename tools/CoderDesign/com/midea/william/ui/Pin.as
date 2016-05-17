package com.midea.william.ui 
{
	
	import flash.display.MovieClip;
	import flash.text.TextField;
	
	
	public class Pin extends MovieClip
	{
		public var designator_txt:TextField;
		public var des_txt:TextField;
		
		private var _designator:int;
		
		private var _portIn:String;
		private var _portOut:String;
		private var _access:String;
		private var _interrupt:String;
		private var _adc:String;
		private var _tx:String;
		private var _rx:String;
		private var _pwm:String;
		
		public function Pin(info:XML)
		{
			this.designator = info.@designator;
			
			des_txt.text = info.des;
			
			this._portIn = info.port_in;
			this._portOut = info.port_out;
			this._access = info.access;
			this._interrupt = info.int;
			this._adc = info.adc;
			this._tx = info.tx;
			this._rx = info.rx;
			this._pwm = info.pwm;
		}
		
		public function set designator(index:int):void
		{
			_designator = index;
			designator_txt.text = index.toString();
		}
		
		public function get designator():int
		{
			return _designator;
		}
		
		public function get portIn():String
		{
			return _portIn;
		}
		
		public function get portOut():String
		{
			return _portOut;
		}
		
		public function get access():String
		{
			return _access;
		}
		
		public function get interrupt():String
		{
			return _interrupt;
		}
		
		public function get adc():String
		{
			return _adc;
		}
		
		public function get tx():String
		{
			return _tx;
		}
		
		public function get rx():String
		{
			return _rx;
		}
		
		public function get pwm():String
		{
			return _pwm;
		}
	}
	
}
