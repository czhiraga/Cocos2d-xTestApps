package to.grenge.from.cyberz.activity;

import android.app.NativeActivity;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;

public class GrengeActivity extends NativeActivity {
	
	private static Context context = null;
	
	public static Context getContext() {
		return context;
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		
		context = this;
		
	}
	
	public static void launchUrl(Context context, String path) {
		Intent i = new Intent(Intent.ACTION_VIEW, Uri.parse(path));
		context.startActivity(i);
	}
	

}
