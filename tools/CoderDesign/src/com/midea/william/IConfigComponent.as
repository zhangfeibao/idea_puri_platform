package com.midea.william
{
	public interface IConfigComponent
	{
		function set sysParameter(para:int):void;
		function get sysParameter():int;
		
		function get macroName():String;
	}
}