package model;

public class PlaceInfo {
	private int building;
	private int play;
	private int satisfaction;

	public PlaceInfo() {
		building = -1;
		play = 0;
		satisfaction = 0;
	}

	public void setBuildng(int building) {
		this.building = building;
	}

	public int getBuilding() {
		return this.building;
	}

	public void setPlay(int play) {
		this.play = play;
	}

	public int getPlay() {
		return this.play;
	}

	public void setSatisfaction(int satisfaction) {
		this.satisfaction = satisfaction;
	}

	public int getSatisfaction() {
		return this.satisfaction;
	}
}
